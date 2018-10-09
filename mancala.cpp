#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
struct Board
{
    int man1;
    vector<int> row1;
    int man2;
    vector<int>row2;
    Board(){}
    Board(int man1,vector<int>row1,int man2,vector<int>row2)
    {
        this->man1=man1;
        this->row1=row1;
        this->man2=man2;
        this->row2=row2;
    }


};

int first_heuristic(struct Board board,bool player)
{
    int diff_storage=board.man1-board.man2;
    int player1=0,player2=0;
    for(int i=0;i<6;i++)player1+=board.row1[i];
    for(int i=0;i<6;i++)player2+=board.row2[i];

    int diff_side=player1-player2;
    int arr[6];

    int cnt1=0;
    for(int i=0;i<=5;i++){
        if(board.row1[i]==0)continue;
        int cnt=board.row1[i];
        int id=i;
        while(cnt){

            id=(id+1)%14;
            if(id!=13)cnt--;
        }
        if(id<6)cnt1++;

    }

    int cnt2=0;
    for(int i=0;i<=5;i++){
        if(board.row2[i]==0)continue;
        int cnt=board.row2[i];
        int id=i;
        while(cnt){

            id=(id+1)%14;
            if(id!=6)cnt--;
        }
        if(id>6 && id<13)cnt2++;

    }


    int ans=10*diff_storage+3*diff_side;
    if(player)ans+=15*cnt1;
    else ans-=15*cnt2;
    return ans;


}

int second_heuristic(struct Board board,bool player)
{
    int point=0;

    if(player){

        for(int i=0;i<=5;i++){

            if(board.row1[i]==0)continue;
            Board temp=board;
            int cnt=board.row1[i];
            temp.row1[i]=0;
            int id=i+1;
            while(cnt){
                if(id==13){
                    id=0;
                    continue;
                }
                if(id==6){
                    temp.man1++;
                }
                else if(id<6)temp.row1[i]++;
                else temp.row2[12-i]++;


                cnt--;
                if(cnt)id=(id+1)%14;

            }
            int cur=first_heuristic(temp,!player);

            if(board.row1[i]==12)point=max(point,cur+30*board.row2[5-id]);
            else if(id<=5 && board.row1[id]==0 && board.row1[i]<12)point=max(point,cur+30*board.row2[5-id]);


        }
        return point;

    }

    else{

        for(int i=0;i<=5;i++){

            if(board.row2[i]==0)continue;
            Board temp=board;
            int cnt=board.row2[i];
            temp.row2[i]=0;
            int id=i+1;
            while(cnt){
                if(id==13){
                    id=0;
                    continue;
                }
                if(id==6){
                    temp.man2++;
                }
                else if(id<6)temp.row2[i]++;
                else temp.row1[12-i]++;


                cnt--;
                if(cnt)id=(id+1)%14;

            }
            int cur=first_heuristic(temp,!player);

            if(board.row2[i]==12)point=max(point,cur+30*board.row1[5-id]);
            else if(id<=5 && board.row2[id]==0 && board.row2[i]<12)point=max(point,cur+30*board.row1[5-id]);


        }
        return point;


    }


}


int main()
{

}

