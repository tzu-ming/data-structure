#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
//打開檔案
fstream textfile1;
textfile1.open("tertis.data.txt");

//根據第一行建立matrix
string first_line;
getline(textfile1,first_line);
istringstream f(first_line);
int row_num,col_num;
f>>row_num>>col_num;
row_num=row_num+1;  //在最上面加一行 重要!!
int c[row_num][col_num]={};

//根據接下來的每行做運算
string whole_line;
while(getline(textfile1,whole_line)){ //當讀取完一行input後，對該行做以下事情: 1.先判斷block的種類  2.再判斷有沒有滿的row要消
       istringstream s(whole_line);
       string type;
       int position;
       int base=row_num-1;
       int b1,b2,b3,b4;
       if(s>>type>>position){                    //若type與position有正確接收到值
            position=position-1;


          if(type.compare("T1") == 0){           //若block為T1
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+1]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-1][position+2]==0){
                       c[i][position+1]=c[i-1][position]=c[i-1][position+1]=c[i-1][position+2]=1;
                       break;
                    }
                }
          }
          else if(type.compare("T2") == 0){      //若block為T2
                for(int k=0;k<row_num;k++){
                    if(c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+1]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-2][position+1]==0){
                       c[i][position+1]=c[i-1][position]=c[i-1][position+1]=c[i-2][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("T3") == 0){      //若block為T3
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1||c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i][position+2]==0&&c[i-1][position+1]==0){
                       c[i][position]=c[i][position+1]=c[i][position+2]=c[i-1][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("T4") == 0){      //若block為T4
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-2][position]==0){
                       c[i][position]=c[i-1][position]=c[i-1][position+1]=c[i-2][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("L1") == 0){      //若block為L1
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i-1][position]==0&&c[i-2][position]==0){
                       c[i][position]=c[i][position+1]=c[i-1][position]=c[i-2][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("L2") == 0){      //若block為L2
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-1][position+2]==0){
                       c[i][position]=c[i-1][position]=c[i-1][position+1]=c[i-1][position+2]=1;
                       break;
                    }
                }
          }
          else if(type.compare("L3") == 0){      //若block為L3
                for(int k=0;k<row_num;k++){
                    if(c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+1]==0&&c[i-1][position+1]==0&&c[i-2][position+1]==0&&c[i-2][position]==0){
                       c[i][position+1]=c[i-1][position+1]=c[i-2][position+1]=c[i-2][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("L4") == 0){      //若block為L4
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1||c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i][position+2]==0&&c[i-1][position+2]==0){
                       c[i][position]=c[i][position+1]=c[i][position+2]=c[i-1][position+2]=1;
                       break;
                    }
                }
          }
          else if(type.compare("J1") == 0){      //若block為J1
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i-1][position+1]==0&&c[i-2][position+1]==0){
                       c[i][position]=c[i][position+1]=c[i-1][position+1]=c[i-2][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("J2") == 0){      //若block為J2
              for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1||c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i][position+2]==0&&c[i-1][position]==0){
                       c[i][position]=c[i][position+1]=c[i][position+2]=c[i-1][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("J3") == 0){      //若block為J3
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i-1][position]==0&&c[i-2][position]==0&&c[i-2][position+1]==0){
                       c[i][position]=c[i-1][position]=c[i-2][position]=c[i-2][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("J4") == 0){      //若block為J4
                for(int k=0;k<row_num;k++){
                    if(c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+2]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-1][position+2]==0){
                       c[i][position+2]=c[i-1][position]=c[i-1][position+1]=c[i-1][position+2]=1;
                       break;
                    }
                }
          }
          else if(type.compare("S1") == 0){      //若block為S1
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i-1][position+1]==0&&c[i-1][position+2]==0){
                       c[i][position]=c[i][position+1]=c[i-1][position+1]=c[i-1][position+2]=1;
                       break;
                    }
                }
          }
          else if(type.compare("S2") == 0){      //若block為S2
                for(int k=0;k<row_num;k++){
                    if(c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+1]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-2][position]==0){
                       c[i][position+1]=c[i-1][position]=c[i-1][position+1]=c[i-2][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("Z1") == 0){      //若block為Z1
                for(int k=0;k<row_num;k++){
                    if(c[k][position+1]==1||c[k][position+2]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position+1]==0&&c[i][position+2]==0&&c[i-1][position]==0&&c[i-1][position+1]==0){
                       c[i][position+1]=c[i][position+2]=c[i-1][position]=c[i-1][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("Z2") == 0){      //若block為Z2
                for(int k=0;k<row_num;k++){
                    if(c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i-1][position]==0&&c[i-1][position+1]==0&&c[i-2][position+1]==0){
                       c[i][position]=c[i-1][position]=c[i-1][position+1]=c[i-2][position+1]=1;
                       break;
                    }
                }
          }
          else if(type.compare("I1") == 0){      //若block為I1
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i-1][position]==0&&c[i-2][position]==0&&c[i-3][position]==0){
                       c[i][position]=c[i-1][position]=c[i-2][position]=c[i-3][position]=1;
                       break;
                    }
                }
          }
          else if(type.compare("I2") == 0){      //若block為I2
                for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1||c[k][position+2]==1||c[k][position+3]==1){
                       base=k;
                       break;
                    }
                }
                for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i][position+2]==0&&c[i][position+3]==0){
                       c[i][position]=c[i][position+1]=c[i][position+2]=c[i][position+3]=1;
                       break;
                    }
                }
          }
          else if(type.compare("O") == 0){       //若block為O
            for(int k=0;k<row_num;k++){
                    if(c[k][position]==1||c[k][position+1]==1){
                       base=k;
                       break;
                    }
                }
            for(int i=base;i>=0;i--){
                    if(c[i][position]==0&&c[i][position+1]==0&&c[i-1][position]==0&&c[i-1][position+1]==0){
                       c[i][position]=c[i][position+1]=c[i-1][position]=c[i-1][position+1]=1;
                       break;
                    }
                }
          }
          else {
          }
          int exist_zero=0;
          int eliminate[row_num]={0};


          //判定有沒有滿的row
          for(int n=row_num-1;n>=0;n--){


                  for(int m=0;m<col_num;m++){  //檢查此row是否有0
                     if(c[n][m]==0){
                         exist_zero=1;
                        }
                     }

                   if(exist_zero!=1){           //若整行都為1就記錄下來
                      eliminate[n]=1;
                     }
              exist_zero=0;
             }


          //消掉所有滿的row
          int destroy=0;  //判定有沒有消過row
          for(int i=row_num-1;i>=0;i--){
            if(eliminate[i]==1){     //若第i行滿了
               destroy=1;
               for(int j=0;j<col_num;j++){ //消掉第i個row
                    c[i][j]=0;
                    }
            }
          }


          //上面的row往下補 每個row往下到最底即停止
        if(destroy==1){
          for (int i=row_num-2;i>=0;i--) {
                int base;
                int min_base=row_num-1;
                int token=0;

               for(int j=0;j<col_num;j++){
                  if(c[i][j]==1){  //找出非0元素
                          for(int k=i+1;k<row_num;k++){
                              if(c[k][j]==1){
                                 token=1;
                                 base=k-1;
                                 if(base<=min_base){
                                    min_base=base;
                                 }
                                 break;
                               }
                          }
                  }
               }
               if(token==1){
                  for(int l=0;l<col_num;l++){
                     c[min_base][l]=c[i][l];   //往下移至base
                     c[i][l]=0;                //將原本的row變成0
                  }
               }
          }
        }

          cout<<type<<" "<<position+1<<endl; //將讀取到的資料cout出來


       } // if(s>>type>>position)的括弧
} // while(getline(textfile1,whole_line))的括弧
textfile1.close();


//cout結果
for(int i=0;i<row_num;i++){
    for(int j=0;j<col_num;j++){
        if(j<col_num-1){
          cout<<c[i][j] ;
        }
        else{
            cout<<c[i][j]<<endl;
        }
    }
}


// output結果到txt檔
fstream textfile2;
textfile2.open ("tertis.final.txt");
for(int i=0;i<row_num;i++){               //把每一個element cout出來
    for(int j=0;j<col_num;j++){
        if(j!=col_num-1){
            textfile2<<c[i][j]<<" ";
        }
        else{
            textfile2<<c[i][j]<<endl;
        }
    }
}

return 0;
}
