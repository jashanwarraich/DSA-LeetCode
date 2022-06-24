// Q47 https://www.codingninjas.com/codestudio/problems/975277?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

// Time: O(amt)
// Space: O(1)

int findMinimumCoins(int amt) 
{
    int deno[9]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int c=0;
    for(int i=8;i>=0;i--){
        while(amt>=deno[i]){
            amt-=deno[i];
            c++; // if asked for the list if coins here we can push back the deno[i] in vector
        }
    }
    return c;
}
