class Solution(object):
    def canMeasureWater(self, x, y, target):
         visited = set()  
          

         def dfs(jug1,jug2):

             if(jug1,jug2) in visited :
                return False

             if(jug1==target or jug2==target or jug1+jug2==target):
                return True

             visited.add((jug1,jug2))

             if(dfs(x,jug2)):
                return True
             if(dfs(jug1,y)):
                return True
             if(dfs(0,jug2)):
                return True
             if(dfs(jug1,0)):
                return True
             if dfs(max(0, jug1 - (y - jug2)), min(y, jug1 + jug2)):
                return True
            # Pour jug2 into jug1
             if dfs(min(x, jug1 + jug2), max(0, jug2 - (x - jug1))):
                return True
            
             return False

         return dfs(0,0)

        