#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include <stdlib.h>
using namespace std;

int main(){

// *********************************************initiate each matrix*********************************************************

fstream input;                 //read the first line and create floor
fstream output;
string first_line;
input.open("floor.data");
int row_num,col_num,battery;
getline(input,first_line);
istringstream f(first_line);
f>>row_num>>col_num>>battery;


string whole_line;
int start_row,start_col;
int block_num=0;
char c;

char floor[row_num][col_num]={};
for(int i=0; i<row_num; i++){  //initiate floor
getline(input,whole_line);
    for(int j=0; j<col_num; j++){
        c= whole_line[j];
        if(c=='R'){
           floor[i][j]=c;
           start_row=i;
           start_col=j;
           block_num=block_num+1;
        }
        else if(c=='0'){
           floor[i][j]=c;   //floor[i][j]=c-'0'; char to int
           block_num=block_num+1;
        }
        else {
           floor[i][j]=c;
        }
    }
}


bool get[row_num][col_num];
for(int i=0;i<row_num;i++){    //initiate get
    for(int j=0;j<col_num;j++){
        get[i][j]=false;
    }
}


int dist[row_num][col_num];
for(int i=0;i<row_num;i++){
    for(int j=0;j<col_num;j++){ //initiate dist
        dist[i][j]=2147483647;
    }
}
dist[start_row][start_col]=0;


bool visit[row_num][col_num];
for(int i=0;i<row_num;i++){    //initiate visit
    for(int j=0;j<col_num;j++){
        visit[i][j]=false;
    }
}


// *********************************************calculate minimum distance***************************************************
int min_dist,min_dist_row,min_dist_col;
//min_dist=2147483647;

for(int k=0; k<block_num; k++){

    min_dist=2147483647;
    for(int i=0;i<row_num;i++){        // choose block with min_dist
      for(int j=0;j<col_num;j++){
        if(floor[i][j]!='1' && dist[i][j]<min_dist && get[i][j]==false){
            min_dist=dist[i][j];
            min_dist_row=i;
            min_dist_col=j;
        }
      }
    }

    get[min_dist_row][ min_dist_col]=true;  // set block to true

    if(floor[min_dist_row][min_dist_col-1]=='0' && get[min_dist_row][min_dist_col-1]==false){   // update dist of left block
         dist[min_dist_row][min_dist_col-1]=(dist[min_dist_row][min_dist_col-1]<dist[min_dist_row][min_dist_col]+1)? dist[min_dist_row][min_dist_col-1]:dist[min_dist_row][min_dist_col]+1;
    }

    if(floor[min_dist_row-1][min_dist_col]=='0' && get[min_dist_row-1][min_dist_col]==false){    // update dist of upper block
         dist[min_dist_row-1][min_dist_col]=(dist[min_dist_row-1][min_dist_col]<dist[min_dist_row][min_dist_col]+1)? dist[min_dist_row-1][min_dist_col]:dist[min_dist_row][min_dist_col]+1;
    }

    if(floor[min_dist_row][min_dist_col+1]=='0' && get[min_dist_row][min_dist_col+1]==false){    // update dist of right block
         dist[min_dist_row][min_dist_col+1]=(dist[min_dist_row][min_dist_col+1]<dist[min_dist_row][min_dist_col]+1)? dist[min_dist_row][min_dist_col+1]:dist[min_dist_row][min_dist_col]+1;
    }

    if(floor[min_dist_row+1][min_dist_col]=='0' && get[min_dist_row+1][min_dist_col]==false){    // update dist of down block
         dist[min_dist_row+1][min_dist_col]=(dist[min_dist_row+1][min_dist_col]<dist[min_dist_row][min_dist_col]+1)? dist[min_dist_row+1][min_dist_col]:dist[min_dist_row][min_dist_col]+1;
    }
}



// *********************************************traverse floor************************************************************************************

int max_dist;
int current_dist=0;
int current_row;
int current_col;
int visit_block_num=0;   // count how many blocks are visited 包在最外面的 while
int path1[2][battery];
int path2[2][battery];
int extend;
int return_dist;
int done;
int total_step=0;
output.open("final.path");
output<<"                                               "<<endl;
output<<start_row<<" "<<start_col<<endl;


while(done!=block_num){
//for(int t=1;t<=6;t++){

    for(int i=0;i<row_num;i++){        // choose unvisited block with max dist
      for(int j=0;j<col_num;j++){
        if(floor[i][j]!='1' && dist[i][j]>=current_dist && visit[i][j]==false){
            current_dist=dist[i][j];
            current_row=i;
            current_col=j;
        }
      }
    }

    max_dist=current_dist;
    path1[0][0]=current_row;
    path1[1][0]=current_col;
    visit[current_row][current_col]=true;
    //cout<<path1[0][0]<<" "<<path1[1][0]<<endl;


for(int k=1;k<=max_dist-1;k++){                               // calculate path1
    if(dist[current_row][current_col-1]==current_dist-1 && visit[current_row][current_col-1]==false){     // go left unvisited
        current_dist=dist[current_row][current_col-1];
        current_col=current_col-1;
    }

    else if(dist[current_row-1][current_col]==current_dist-1 && visit[current_row-1][current_col]==false){     // go up unvisited
        current_dist=dist[current_row-1][current_col];
        current_row=current_row-1;
    }

    else if(dist[current_row][current_col+1]==current_dist-1 && visit[current_row][current_col+1]==false){     // go right unvisited
        current_dist=dist[current_row][current_col+1];
        current_col=current_col+1;
    }

    else if(dist[current_row+1][current_col]==current_dist-1 && visit[current_row+1][current_col]==false){     // go down unvisited
        current_dist=dist[current_row+1][current_col];
        current_row=current_row+1;
    }

    else if(dist[current_row][current_col-1]==current_dist-1){     // go left
        current_dist=dist[current_row][current_col-1];
        current_col=current_col-1;
    }

    else if(dist[current_row-1][current_col]==current_dist-1){     // go up
        current_dist=dist[current_row-1][current_col];
        current_row=current_row-1;
    }

    else if(dist[current_row][current_col+1]==current_dist-1){     // go right
        current_dist=dist[current_row][current_col+1];
        current_col=current_col+1;
    }

    else if(dist[current_row+1][current_col]==current_dist-1){     // go down
        current_dist=dist[current_row+1][current_col];
        current_row=current_row+1;
    }

        path1[0][k]=current_row;  // update path1
        path1[1][k]=current_col;
        visit[current_row][current_col]=true;
        //cout<<path1[0][k]<<" "<<path1[1][k]<<endl;
}


/*
for(int i=max_dist-1;i>=0;i--){
    cout<<path1[0][i]<<" "<<path1[1][i]<<endl;
}
*/







// calculate path2 extend
int step=max_dist; // the step from R to current block
extend=0;
bool no_way=false;
current_row=path1[0][0];
current_col=path1[1][0];

while(no_way==false){
if((battery-step-1)>=dist[current_row][current_col-1] && visit[current_row][current_col-1]==false){     // go left unvisited
        current_col=current_col-1;
        extend=extend+1;
        step=step+1;
    }

else if((battery-step-1)>=dist[current_row-1][current_col] && visit[current_row-1][current_col]==false){     // go up unvisited
        current_row=current_row-1;
        extend=extend+1;
        step=step+1;
    }

else if((battery-step-1)>=dist[current_row][current_col+1] && visit[current_row][current_col+1]==false){     // go right unvisited
        current_col=current_col+1;
        extend=extend+1;
        step=step+1;
    }

else if((battery-step-1)>=dist[current_row+1][current_col] && visit[current_row+1][current_col]==false){     // go down unvisited
        current_row=current_row+1;
        extend=extend+1;
        step=step+1;
    }


else  {                  // no way
   no_way=true;
}

if(visit[current_row][current_col]==false && no_way==false){   // update path2
    path2[0][extend-1]=current_row;
    path2[1][extend-1]=current_col;
    visit[current_row][current_col]=true;
    //cout<<path2[0][extend-1]<<" "<<path2[1][extend-1]<<endl;
}



 }


// calculate path2 return
// start from current_row and current_col
return_dist=dist[current_row][current_col];
current_dist=return_dist;


for(int k=1;k<=return_dist-1;k++){
    if(dist[current_row][current_col-1]==current_dist-1 && visit[current_row][current_col-1]==false){     // go left unvisited
        current_dist=dist[current_row][current_col-1];
        current_col=current_col-1;
    }

    else if(dist[current_row-1][current_col]==current_dist-1 && visit[current_row-1][current_col]==false){     // go up unvisited
        current_dist=dist[current_row-1][current_col];
        current_row=current_row-1;
    }

    else if(dist[current_row][current_col+1]==current_dist-1 && visit[current_row][current_col+1]==false){     // go right unvisited
        current_dist=dist[current_row][current_col+1];
        current_col=current_col+1;
    }

    else if(dist[current_row+1][current_col]==current_dist-1 && visit[current_row+1][current_col]==false){     // go down unvisited
        current_dist=dist[current_row+1][current_col];
        current_row=current_row+1;
    }

    else if(dist[current_row][current_col-1]==current_dist-1){     // go left
        current_dist=dist[current_row][current_col-1];
        current_col=current_col-1;
    }

    else if(dist[current_row-1][current_col]==current_dist-1){     // go up
        current_dist=dist[current_row-1][current_col];
        current_row=current_row-1;
    }

    else if(dist[current_row][current_col+1]==current_dist-1){     // go right
        current_dist=dist[current_row][current_col+1];
        current_col=current_col+1;
    }

    else if(dist[current_row+1][current_col]==current_dist-1){     // go down
        current_dist=dist[current_row+1][current_col];
        current_row=current_row+1;
    }

        path2[0][extend-1+k]=current_row;  // update path1
        path2[1][extend-1+k]=current_col;
        visit[current_row][current_col]=true;
        //cout<<path2[0][extend-1+k]<<" "<<path2[1][extend-1+k]<<endl;
}
path2[0][extend-1+return_dist]=start_row;
path2[1][extend-1+return_dist]=start_col;

//output path1 and path2 to final.path

for(int i=max_dist-1;i>=0;i--){
    output<<path1[0][i]<<" "<<path1[1][i]<<endl;
}


for(int i=0;i<=extend-1+return_dist;i++){
    output<<path2[0][i]<<" "<<path2[1][i]<<endl;
}







total_step=total_step+max_dist+extend+return_dist;



done=0;
for(int i=0;i<row_num;i++){
    for(int j=0;j<col_num;j++){
        if(floor[i][j]=='0' && visit[i][j]==1){
           done=done+1;
        }

        else if(floor[i][j]=='R'){
            done=done+1;
        }
    }
}



}
output.close();
output.open("final.path");
output<<total_step;
output.close();








return 0;
}
