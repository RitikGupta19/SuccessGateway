#include <iostream>
using namespace std;

void shift(int a[], int k, int n)
{
  int i;
  for (i = k; i < n - 1; i++)
  {
    a[i] = a[i + 1];
  }
}

int main()
{
  int t, N, a[100], i, temp;
  cin >> t;
  while (t--)
  {
    cin >> N;
    for (i = 0; i < N; i++)
    {
      cin >> a[i];
    }

    for (i = 0; i < N; i++)
    {
      if (a[i] < 0)
      {
        temp = a[i];
        shift(a, i, N);
        a[N - 1] = temp;
        if (a[i] < 0)
          i--;
      }
    }

    for (i = 0; i < N; i++)
      cout << a[i] << " ";
    cout << endl;
  }
  return 0;
}