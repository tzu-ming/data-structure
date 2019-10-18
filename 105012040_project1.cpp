#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
//���}�ɮ�
fstream textfile1;
textfile1.open("Tetris.data");

//�ھڲĤ@��إ�matrix
string first_line;
getline(textfile1,first_line);
istringstream f(first_line);
int row_num,col_num;
f>>row_num>>col_num;
row_num=row_num+4;
int c[row_num][col_num]={};

//�ھڱ��U�Ӫ��C�氵�B��
string whole_line;
while(getline(textfile1,whole_line)){ //��Ū�����@��input��A��Ӧ氵�H�U�Ʊ�: 1.���P�_block������  2.�A�P�_���S������row�n��
       istringstream s(whole_line);
       string type;
       int position;
       int base=row_num-1;
       int b1,b2,b3,b4;
       if(s>>type>>position){                    //�Ytype�Pposition�����T�������
            position=position-1;


          if(type.compare("T1") == 0){           //�Yblock��T1
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
          else if(type.compare("T2") == 0){      //�Yblock��T2
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
          else if(type.compare("T3") == 0){      //�Yblock��T3
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
          else if(type.compare("T4") == 0){      //�Yblock��T4
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
          else if(type.compare("L1") == 0){      //�Yblock��L1
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
          else if(type.compare("L2") == 0){      //�Yblock��L2
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
          else if(type.compare("L3") == 0){      //�Yblock��L3
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
          else if(type.compare("L4") == 0){      //�Yblock��L4
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
          else if(type.compare("J1") == 0){      //�Yblock��J1
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
          else if(type.compare("J2") == 0){      //�Yblock��J2
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
          else if(type.compare("J3") == 0){      //�Yblock��J3
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
          else if(type.compare("J4") == 0){      //�Yblock��J4
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
          else if(type.compare("S1") == 0){      //�Yblock��S1
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
          else if(type.compare("S2") == 0){      //�Yblock��S2
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
          else if(type.compare("Z1") == 0){      //�Yblock��Z1
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
          else if(type.compare("Z2") == 0){      //�Yblock��Z2
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
          else if(type.compare("I1") == 0){      //�Yblock��I1
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
          else if(type.compare("I2") == 0){      //�Yblock��I2
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
          else if(type.compare("O") == 0){       //�Yblock��O
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


          //�P�w���S������row
          for(int n=row_num-1;n>=4;n--){


                  for(int m=0;m<col_num;m++){  //�ˬd��row�O�_��0
                     if(c[n][m]==0){
                         exist_zero=1;
                        }
                     }

                   if(exist_zero!=1){           //�Y��泣��1�N�O���U��
                      eliminate[n]=1;
                     }
              exist_zero=0;
             }


          //�����Ҧ�����row
          int destroy=0;  //�P�w���S�����Lrow
          for(int i=row_num-1;i>=4;i--){
            if(eliminate[i]==1){     //�Y��i�溡�F
               destroy=1;
               for(int j=0;j<col_num;j++){ //������i��row
                    c[i][j]=0;
                    }
            }
          }


          //�W����row���U�� �C��row���U��̩��Y����
          if(destroy==1){
             for(int i=row_num-2;i>=4;i--){


                         //�ˬd�U���ŴX��
                         int empty_line=0;
                         for(int ii=i+1;ii<=row_num-1;ii++){ //�p��empty_line
                            int isempty=1;
                            for(int j=0;j<col_num;j++){
                                if (c[ii][j]==1){ isempty=0; }
                            }

                            if(isempty==1){
                                empty_line++;
                            }
                            if(isempty==0){
                                break;
                            }
                         }


                         //�Y���Ŧ�N���U��
                         if(empty_line!=0){
                            for (int j=0;j<col_num;j++){
                                c[i+empty_line][j]=c[i][j];
                                c[i][j]=0;
                           }
                        }


                 }
          }


          //�P�_end game
          int end_game=0;
                for(int b=0;b<col_num;b++){
                    if(c[3][b]==1){end_game=1;}
                }
          // ����end game
          if (end_game==1){break;}





          cout<<type<<" "<<position+1<<endl; //�NŪ���쪺���cout�X��


       } // if(s>>type>>position)���A��
} // while(getline(textfile1,whole_line))���A��
textfile1.close();


//cout���G
for(int i=4;i<row_num;i++){
    for(int j=0;j<col_num;j++){
        if(j<col_num-1){
          cout<<c[i][j] ;
        }
        else{
            cout<<c[i][j]<<endl;
        }
    }
}





// output���G��txt��
fstream textfile2;
textfile2.open ("Tetris.output");
for(int i=4;i<row_num;i++){               //��C�@��element cout�X��
    for(int j=0;j<col_num;j++){
        if(j!=col_num-1){
            textfile2<<c[i][j];
        }
        else{
            textfile2<<c[i][j]<<endl;
        }
    }
}

return 0;
}
