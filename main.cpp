#include <bits/stdc++.h>

using namespace std;

#define md 1000000007
#define ll long long
#define ull unsigned long long
#define si short int

int getResult(int a[], int b[], int n, int m)
{
    int sum1 = 0;
    int sum2 = 0;
    int j = 0, i = 0;
    int res = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            sum1 += a[i++];
        }
        else if (b[j] < a[i])
        {
            sum2 += b[j++];
        }
        else
        {
            res += max(sum1, sum2);
            sum1 = 0;
            sum2 = 0;

            int temp = i;
            while (i < n && a[i] == b[j])
            {
                sum1 += a[i++];
            }
            while (j < m && a[temp] == b[j])
            {
                sum2 += b[j++];
            }
            res += max(sum1, sum2);
            sum1 = 0, sum2 = 0;
        }
    }
    while (i < n)
    {
        sum1 += a[i++];
    }
    while (j < m)
    {
        sum2 += b[j++];
    }
    res += max(sum1, sum2);

    return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        int result = getResult(a, b, n, m);
        cout << result << "\n";
    }
    return 0;
}
