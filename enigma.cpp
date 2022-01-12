// Symulator Enigmy
// Data: 22.08.2008
// (C)2020 mgr Jerzy Wałaszek
//-----------------------------

#include <iostream>
#include <string>

using namespace std;

// definicje elementów Enigmy

const string pierscien_szyfr [ 5 ] = {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", 
                                      "AJDKSIRUXBLHWTMCQGZNPYFVOE", 
                                      "BDFHJLCPRTXVZNYEIWGAKMUSQO", 
                                      "ESOVPZJAYQUIRHXLNFTGKDCMWB", 
                                      "VZBRGITYUPSDNHLXAWMJQOFECK"};
const string przeniesienie         =  "RFWKA";
const string beben_odwr            =  "YRUHQSLDPXNGOKMIEBFZCWVJAT";

int main( )
{
  int pierscien [ 3 ], i, j, k, n, c;
  bool ruch;
  string szyfr, s, lacznica;


// odczytujemy konfigurację pierścieni szyfrujących

  cin >> n;

  for( i = 2; i >= 0; i-- )
  {
    pierscien [ i ] = ( n % 10 ) - 1; // numer pierścienia na i-tej pozycji
    n /= 10;
  }

// odczytujemy położenia początkowe pierścieni

  cin >> szyfr;
  for( i = 0; i < szyfr.length( ); i++ ) szyfr [ i ] = toupper ( szyfr [ i ] );

// odczytujemy stan łącznicy wtyczkowej

  cin >> s;
  for( i = 0; i < s.length( ); i++ ) s [ i ] = toupper ( s [ i ] );
  
  lacznica = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for( i = 0; i < s.length( ) - 1; i += 2 )
  {
    lacznica [ s [ i ] - 65 ] = s [ i + 1 ];
    lacznica [ s [ i + 1 ] - 65 ] = s [ i ];
  }

// odczytujemy szyfrogram

  cin.ignore ( 256, '\n' );
  getline ( cin, s );
  for( i = 0; i < s.length( ); i++ ) s [ i ] = toupper ( s [ i ] );

// szyfrujemy/rozszyfrowujemy szyfrogram

  for( i = 0; i < s.length( ); i++ )
  {

// najpierw ruch pierścieni szyfrujących

    for( ruch = true, j = 2; ruch && ( j >= 0 ); j-- )
    {
      ruch = ( szyfr [ j ] == przeniesienie [ pierscien [ j ] ] );
      szyfr [ j ] = 65 + ( szyfr [ j ] - 64 ) % 26;
    }

// pobieramy znak szyfrogramu

    c = s [ i ];

// przechodzimy przez łącznicę wtyczkową

    c = lacznica [ c - 65 ];

// przechodzimy przez pierścienie w kierunku do bębna odwracającego

    for( j = 2; j >= 0; j-- )
    {
      k = szyfr [ j ] - 65;
      c = pierscien_szyfr [ pierscien [ j ] ][ ( c - 65 + k ) % 26 ];
      c = 65 + ( c - 39 - k ) % 26;
    }

// przechodzimy przez bęben odwracający

    c = beben_odwr [ c - 65 ];

// wracamy ścieżką powrotną

    for( j = 0; j < 3; j++ )
    {
      k = szyfr [ j ] - 65;
      c = 65 + ( c - 65 + k ) % 26;
      for( n = 0; pierscien_szyfr [ pierscien [ j ] ][ n ] != c; n++ );
      c = 65 + ( 26 + n - k ) % 26;
    }

// przechodzimy przez łącznicę wtyczkową

    c = lacznica [ c - 65 ];

// uaktualniamy szyfrogram

    s [ i ] = c;

  }

// wyświetlamy szyfrogram

  cout << s << endl << endl;
  return 0;
} 