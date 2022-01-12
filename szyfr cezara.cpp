// Szyfrowanie Kodem Cezara
// Data: 18.08.2008
// (C)2020 mgr Jerzy Wałaszek
//-----------------------------

#include <iostream>
#include <string>

using namespace std;

int main( )
{
  string s;
  int i;

// odczytujemy wiersz znaków

  getline ( cin, s );

// zamieniamy małe litery na duże
// i kodujemy szyfrem cezara

  for( i = 0; i < s.length( ); i++ )
  {
    s [ i ] = toupper ( s [ i ] );
    if( ( s [ i ] >= 'A' ) && ( s [ i ] <= 'Z' ) ) s [ i ] = char ( 65 + ( s [ i ] - 62 ) % 26 );
  }

// wypisujemy zaszyfrowany tekst

  cout << s << endl << endl;
  return 0;
} 