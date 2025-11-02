#include <bits/stdc++.h>
using namespace std;

int dr[8] ={-1,-1,-1,0,0,1,1,1};
int dc[8] = {-1,0,1,-1,1,-1,0,1};

vector<pair<int,int>> moves(const vector<string>&bd,int r,int c,char player){
    char op=(player=='X'?'O':'X');
        if (bd[r][c]=='X' || bd[r][c]=='O') return {};
    vector<pair<int,int>> all;
    for(int d=0;d<8;d++){
        int rr=r+dr[d],cc=c+dc[d];
        vector<pair<int,int>> seg;
        while(rr>=0&&rr<8&&cc>=0&&cc<8&&bd[rr][cc]==op){
            seg.emplace_back(rr,cc);
            rr+=dr[d];cc+=dc[d];
        }
        if(!seg.empty()&&rr>=0&&rr<8&&cc>=0&&cc<8&&bd[rr][cc]==player){
            all.insert(all.end(),seg.begin(),seg.end());
        }    
    }
        return all;
}

struct Move {
    int r,c;
    vector<string> board; 
};

vector<Move> legal_moves(const vector<string>& bd, char player){
    vector<Move> res;
    for(int r=0;r<8;++r) for(int c=0;c<8;++c){
        auto flips = moves(bd,r,c,player);
        if(!flips.empty()){
            vector<string> nb = bd;
            nb[r][c] = player;
            for(auto &p: flips) nb[p.first][p.second] = player;
            res.push_back({r,c,nb});
        }
    }
    return res;
}

int countX(const vector<string>& bd){
    int cnt=0;
    for(int r=0;r<8;++r) for(int c=0;c<8;++c) if(bd[r][c]=='X') ++cnt;
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> board(8);
    for(int i=0;i<8;++i){
        if(!(cin>>board[i])) return 0;
    }

    auto black_moves = legal_moves(board, 'X');
    struct Outcome {
        Move blackMove;
        vector<Move> whiteResponses; 
        int finalBlackCount; 
    };
    vector<Outcome> outcomes;

    for(auto &bm : black_moves){
        vector<Move> white_moves = legal_moves(bm.board, 'O');
        if(white_moves.empty()){
            int fx = countX(bm.board);
            outcomes.push_back({bm, {}, fx});
        }else{
            int minBlack = INT_MAX;
            for(auto &wm : white_moves){
                int cnt = countX(wm.board);
                if(cnt < minBlack) minBlack = cnt;
            }
            vector<Move> chosen;
            for(auto &wm : white_moves){
                if(countX(wm.board) == minBlack) chosen.push_back(wm);
            }
            outcomes.push_back({bm, chosen, minBlack});
        }
    }
    int best = INT_MIN;
    for(auto &oc : outcomes) best = max(best, oc.finalBlackCount);
    vector<Outcome> bestOutcomes;
    for(auto &oc : outcomes) if(oc.finalBlackCount == best) bestOutcomes.push_back(oc);
    cout << "Max X pieces: " << best << "\n";
    for(auto &oc : bestOutcomes){
        cout << "\n";
        auto &bboard = oc.blackMove.board;
        auto &wresps = oc.whiteResponses; 
        int W = (int)wresps.size();
        for(int r=0;r<8;++r){
            cout << bboard[r];
            if(W==0){
                if(r==3){
                    cout << " > pass";
                }
                cout << "\n";
            }else{
                if(r==3) cout << " > ";
                else cout << "   ";
                for(int j=0;j<W;++j){
                    cout << wresps[j].board[r];
                    if(j < W-1){
                        if(r==3) cout << " / ";
                        else cout << "   ";
                    }
                }
                cout << "\n";
            }
        }
    }

    return 0;
}