// Szyfr przestawieniowy
// Data: 12.02.2011
// (C)2020 mgr Jerzy Wałaszek
//-----------------------------

#include <iostream>
#include <string>

using namespace std;

int main( )
{
  string s, t;
  unsigned n, i, j;

  // odczytujemy tekst/szyfr

  getline ( cin, s );

  // dopasowujemy n

  for( n = 1; n * n < s.length( ); n++ );

  // dopasowujemy s

  while( s.length( ) < n * n ) s += ".";

  // szyfrujemy/deszyfrujemy

  t = "";
  for( j = 0; j < n; j++ )
    for( i = 0; i < n; i++ ) t += s [ j + n * i ];

  // wypisujemy wynik

  cout << t << endl;

  return 0;
} 