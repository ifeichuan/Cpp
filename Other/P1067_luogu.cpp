#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, t;
    scanf("%d", &n);
    scanf("%d", &t);
    if (n == 0)
        printf("%d", t);
    else
    {
        if(n==1){
            printf("%dx",t);
        }
        else{
            if(t==1||t==-1){
                if(t>0) printf("");
                else printf("-");
                printf("x^%d",n);
            }
            else printf("%dx^%d",t,n);
        }
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &t);
            if (n - i != 1)
            {
                if (t == 1 || t == -1)
                {
                    if (t > 0)
                        printf("+");
                    else
                        printf("-");
                    printf("x^%d", n - i);
                }
                    else if (t == 0) continue;
                    else{
                        if(t>0) printf("+");
                        printf("%dx^%d",t,n-i);
                    }
                }
            
            else
            {
                if(t==1||t==-1){
                    if(t>0) printf("+");
                    else printf("-");
                    printf("x");
                }
                else if(t==0) continue;
                else{
                                            if(t>0) printf("+");
                        printf("%dx",t);
                }
            
            }
        }
        scanf("%d", &t);
        if(t!=0){
        if (t > 0)
            printf("+");
        printf("%d", t);
    }
    }
}