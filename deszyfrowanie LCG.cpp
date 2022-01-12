// Deszyfrowanie z pseudolosowym odstępem
// Data: 20.08.2008
// (C)2020 mgr Jerzy Wałaszek
//-----------------------------

#include <iostream>
#include <string>

using namespace std;

int main( )
{
  string s;
  int i;
  unsigned long long X, a, m, c;

// definiujemy generator LCG

  m = 3956280000;
  a = 1978141;
  c = 1309ull;

// odczytujemy klucz i szyfr

  cin >> X; cin.ignore ( 256, '\n' );
  getline ( cin, s );

// deszyfrujemy

  for( i = 0; i < s.length( ); i++ )
  {

// obliczamy kolejną liczbę pseudolosową

    X = ( a * X + c ) % m;

// deszyfrujemy literkę

    s [ i ] = toupper ( s [ i ] );
    if( ( s [ i ] >= 'A' ) && ( s [ i ] <= 'Z' ) ) s [ i ] = 65 + ( s [ i ] - 39 - X % 26 ) % 26;
  }

// wypisujemy rozszyfrowany tekst

  cout << s << endl << endl;
  return 0;
} 