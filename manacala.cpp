#include<bits/stdc++.h>
#define total 48
#define ss second
#define ff first
#define maxDepth 12
using namespace std;

int map_1[]={12,11,10,9,8,7};
int map_2[]={0,1,2,3,4,5};


int score_1(vector<int>board,bool player)
{
    int diff_storage=board[6]-board[13];
    int player1=0,player2=0;
    for(int i=0;i<6;i++)player1+=board[i];
    for(int i=7;i<13;i++)player2+=board[i];

    int diff_side=player1-player2;
    int arr[6];

    int cnt1=0;
    for(int i=0;i<=5;i++){
        if(board[i]==0)continue;
        int cnt=board[i];
        int id=i;
        while(cnt){

            id=(id+1)%14;
            if(id!=13)cnt--;
        }
        if(id<6)cnt1++;

    }

    int cnt2=0;
    for(int i=7;i<=12;i++){
        if(board[i]==0)continue;
        int cnt=board[i];
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


int score_2(vector<int>board,bool player)
{
    int score1=INT_MIN;
    int capture_1=0;


    for(int i=0;i<=5;i++){

        if(board[i]==0)continue;
        vector<int>temp=board;
        int cnt=board[i];
        temp[i]=0;
        int id=i+1;
        while(cnt){
            if(id==13){
                id=0;
                continue;
            }
            temp[id]+=1;
            cnt--;
            if(cnt)id++;

        }
        int cur=score_1(temp,!player);

        if(board[i]==12)score1=max(score1,cur+board[map_1[i]]);
        else if(i+board[i]<=5 && board[i+board[i]]==0)score1=max(score1,cur+board[map_1[i]]);

        else if(board[i]<12 && ((i+board[i])%14)<=5 && board[(i+board[i])%14]==0){
            score1=max(score1,cur+board[map_1[i]]);

        }


    }

    int score2=INT_MAX;


    for(int i=7;i<=12;i++){

        vector<int>temp=board;
        int cnt=board[i];
        temp[i]=0;
        int id=i+1;
        while(cnt){
            if(id==6){
                id=7;;
                continue;
            }
            temp[id]+=1;
            cnt--;
            if(cnt)id=(id+1)%14;

        }
        int cur=score_1(temp,!player);
        if(board[i]==12)score2=min(score2,cur-board[map_2[12-i]]);
        else if(i+board[i]<=12 && (i+board[i])>=7 && board[i+board[i]]==0)score2=min(score2,cur-board[map_2[12-i]]);
        else if(board[i]<12 && (i+board[i])%14<=12 && (i+board[i])%14>=7 && board[(i+board[i])%14]==0){
                score2=min(score2,cur-board[map_2[12-i]]);
        }


    }

    if(player)return score1;
    return score2;


}


bool isFinished(vector<int>board)
{
    if(board[6]+board[13]==total)return true;
    int cnt=0;
    for(int i=0;i<=5;i++)cnt+=board[i];
    if(cnt==0)return true;
    cnt=0;
    for(int i=7;i<=12;i++)cnt+=board[i];
    if(cnt==0)return true;
    return false;
}

int winner(vector<int>board)
{
    int cnt1=board[6];
    for(int i=0;i<=5;i++)cnt1+=board[i];
    int cnt2=board[13];
    for(int i=7;i<=12;i++)cnt2+=board[i];

    if(cnt1>cnt2)return 1;
    else if(cnt1<cnt2)return 2;
    return 0;
}


pair<int,int> minimax(vector<int>board,bool player,int alpha,int beta,int depth,bool hr)
{
    //cout<<depth<<endl;
    if(depth==0 ){

        pair<int,int >ans;
        if(hr)ans= make_pair(score_1(board,player),0);

        else ans= make_pair(score_2(board,player),0);

        return ans;

    }

    if(isFinished(board)){

        if(hr)return make_pair(score_1(board,player),0);
        return make_pair(score_2(board,player),0);
    }


    int best;
    int ans;

    if(player)
    {

        best=INT_MIN;
        for(int i=0;i<=5;i++){
            if(board[i]==0)continue;
            vector<int>temp=board;
            int cnt=board[i];
            temp[i]=0;
            int id=i+1;
            while(cnt){
                if(id==13){
                    id=0;
                    continue;
                }
                temp[id]+=1;
                cnt--;
                if(cnt)id++;

            }


            int min_val;

            if(temp[id]==1 && id<=5){
                temp[6]+=temp[map_1[id]];
                temp[map_1[id]]=0;
                min_val=minimax(temp,!player,alpha,beta,depth-1,hr).first;
            }
            else if(id<=5)min_val=minimax(temp,player,alpha,beta,depth-1,hr).first;
            else min_val=minimax(temp,!player,alpha,beta,depth-1,hr).first;

            if(min_val>=best){
                best=min_val;
                ans=i;
            }
            alpha=max(alpha,best);
            if(beta<=alpha)return make_pair(best,ans);

        }
        return make_pair(best,ans);
    }


    best=INT_MAX;
    for(int i=7;i<=12;i++){
        if(board[i]==0)continue;
        vector<int>temp=board;
        int cnt=board[i];
        temp[i]=0;
        int id=i+1;
        while(cnt){
            if(id==6){
                id=7;;
                continue;
            }
            temp[id]+=1;
            cnt--;
            if(cnt)id=(id+1)%14;

        }


        int max_val;

        if(temp[id]==1 && id<=12 && id>=7){
            temp[13]+=temp[map_2[12-id]];
            temp[map_2[12-id]]=0;
            max_val=minimax(temp,!player,alpha,beta,depth-1,hr).ff;
        }
        else if(id<=12 && id>=7)max_val=minimax(temp,player,alpha,beta,depth-1,hr).ff;
        else max_val=minimax(temp,!player,alpha,beta,depth-1,hr).ff;

        if(best>=max_val){
            best=max_val;
            ans=i;
        }
        beta=min(beta,best);
        if(beta<=alpha)return make_pair(best,ans);

    }
    return make_pair(best,ans);


}

int main()
{
    vector<int>board(14,4);
    board[13]=0,board[6]=0;


}
