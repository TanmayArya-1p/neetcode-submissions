class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        n = 9
        for i in range(9):
            mp = {}
            for j in board[i]:
                if(j=='.'):
                    continue
                if(mp.get(j,-1)!=-1):
                    return False
                else:
                    mp[j]=True
            
        print("f1")
        for i in range(9):
            mp = {}
            for j in range(9):
                if(board[j][i]=='.'):
                    continue
                if(mp.get(board[j][i],-1)!=-1):
                    return False
                else:
                    mp[board[j][i]]=True
        
        print("f2")

        for i in range(3):
            for j in range(3):
                mp= {}
                for l in range(3):
                    for f in range(3):
                        if(board[3*i+l][3*j+f]=='.'):
                            continue
                        if(mp.get(board[3*i+l][3*j+f],-1)!=-1):
                            return False
                        else:
                            mp[board[3*i+l][3*j+f]] = True;
        print("f3")
        
        return True




