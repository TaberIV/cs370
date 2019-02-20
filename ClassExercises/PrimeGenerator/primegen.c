#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool *sieve(int max)
{
  bool *primes = (bool *)malloc(sizeof(bool) * (max + 1));

  for (int i = 2; i < max + 1; i++)
  {
    primes[i] = true;
  }

  for (int i = 2; i < max; i++)
  {
    if (primes[i])
    {
      for (int j = i * i; j < max + 1; j += i)
      {
        primes[j] = false;
      }
    }
  }

  return primes;
}

void print_primes(int a, int b)
{
  a = a < 2 ? 2 : a;
  int num_low = (int) sqrt(b);
  bool *low_primes = sieve(num_low);

  int num_high = b - a + 1;
  int high_primes[num_high];

  for (int i = 0; i < num_high; i++) {
    high_primes[i] = true;
  }

  for (int p = 2; p <= num_low; p++)
  {
    int i = (int) ceil((double)a / p) * p - a;
    if (low_primes[p] && a <= p)
    {
      i = i + p;
    }

    for (; i < num_high; i += p) {
      high_primes[i] = false;
    }
  }

  for (int i = 0; i < num_high; i++) {
    if (high_primes[i]) {
      printf("%d\n", i + a);
    }
  }
}

int main()
{
  int n;
  scanf("%d", &n);

  bool *primes = sieve(15);

  while (n > 0)
  {
    int a, b;
    scanf("%d %d", &a, &b);

    print_primes(a, b);

    printf("\n");
    n--;
  }
}