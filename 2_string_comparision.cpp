#include <bits/stdc++.h>

using namespace std;
int Min(int a,int b,int c){
    return min(a,min(b,c));
}

void mPenalty(string a,string b,int pmix,int pgap){
    int i,j;
    int xlen=a.length();
    int ylen=b.length();

    int len = xlen+ylen;
    int matrix[len+1][len+1]={0};

    i=0;
    while(i<=xlen+ylen){
        matrix[0][i]= i* pgap;
        matrix[i][0]= i* pgap;
        i++;
    }

    for(j=0;j<xlen;j++){
        for(i=0;i<ylen;i++){
            if(a[j]==b[i]){
                matrix[j+1][i+1]=matrix[j][i];
            }
            else{
                matrix[j+1][i+1]=Min(matrix[j][i]+pmix,matrix[j][i+1]+pgap,matrix[j+1][i]+pgap);
            }
        }
    }
    i=xlen-1;
    j=ylen-1;
    int xpointer =len;
    int ypointer =len;

    int xlist[len+1],ylist[len+1];
    int total=0,r=0;
    while(i>=0 and j>=0){
        if(a[i]==b[j] || (matrix[i][j] + pmix == matrix[i+1][j+1])){
            xlist[xpointer --] = (int)a[i];
            ylist[ypointer--] = (int)b[j];
            i--; j--;
            total=total + pmix;
            r++;
        }
        else if (matrix[i+1][j] + pgap == matrix[i+1][j+1])
        {
            xlist[xpointer--] = (int)'_';
            ylist[ypointer--] = (int)b[j];
            j--;
            total = total + pgap;
            r++;
        }
        else if (matrix[i][j+1] + pgap == matrix[i+1][j+1])
        {
            xlist[xpointer--] = (int)a[i];
            ylist[ypointer--] = (int)'_';
            i--;
            total = total + pgap;
            r++;
        }
    }
    while (xpointer > 0)
    {
        if (i >=0) xlist[xpointer--] = (int)a[--i];
        else xlist[xpointer--] = (int)'_';
    }
    while (ypointer > 0)
    {
        if (j >=0) ylist[ypointer--] = (int)b[--j];
        else ylist[ypointer--] = (int)'_';
    }

    // Since we have assumed the answer to be n+m long,
    // we need to remove the extra gaps in the starting
    // id represents the index from which the arrays
    // xans, yans are useful
    int q = 1;
    for (i = len; i >= 1; i--)
    {
        if ((char)ylist[i] == '_' && (char)xlist[i] == '_')
        {
            q = i + 1;
            break;
        }
    }
    for (i = q; i <= len; i++)
    {
        cout<<(char)xlist[i];
    }
    cout << "\n";
    for (i = q; i <= len; i++)
    {
        cout << (char)ylist[i];
    }
    cout << "\n";
    cout << "Cost = ";
    cout << matrix[xlen][ylen]<< "\n";
    //cout << total/2<< "\n";
    //cout << r;
    return;
}
// Driver code
int main(){
    // input strings
    int w;
    cin >> w;
    string dna1 ;
    string dna2 ;
    cin >> dna1;
    cin >> dna2;

    if(w==1){
    int misMatchPenalty = 4;
    int gapPenalty = 6;
    mPenalty(dna1, dna2 ,misMatchPenalty, gapPenalty);
    return 0;
    }
    if(w==2){
    int misMatchPenalty = 6;
    int gapPenalty = 4;
    mPenalty(dna1, dna2 ,misMatchPenalty, gapPenalty);
    return 0;
    }
}
