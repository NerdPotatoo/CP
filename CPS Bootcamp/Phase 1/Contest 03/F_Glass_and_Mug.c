#include<stdio.h>
#include<math.h>

int main()
{
    int n, g ,m;
    scanf("%d %d %d", &n, &g, &m);
    int x = 0, y = 0, k = 1;
    for(int i = 1; i<=n; i++)
    {
        if(x == g)
        {
            x = 0;
        }
        else if(y == 0)
        {
            y = m;
        }
        else{
            int left = g-x;
            if(left >= y)
            {
                x += y;
                y = 0;
            }
            else{
                y -= left;

                x = g;
            }
        }
    // printf("%d %d %d %d\n",i, x, y, k);
    }
    printf("%d %d", x, y);
}