// Szyfr przestawieniowy
// Data: 19.02.2011
// (C)2020 mgr Jerzy Wałaszek
//-----------------------------

#include <iostream>

using namespace std;

int main( )
{
  string s;
  int i, m, a, c, X0, *T;

  // odczytujemy klucz

  cin >> X0;

  // odczytujemy tekst/szyfr

  cin.ignore ( 255, '\n' );

  getline ( cin, s );

  // definiujemy generator pseudolosowy

  m = 984;
  a = 493;
  c = 385;

  // jeśli klucz > 0, to szyfrujemy
  // inaczej rozszyfrowujemy

  if( X0 > 0 )

    // przestawiamy znaki tekstu

    for( i = 0; i < ( int )s.length( ); i++ )
    {
      // wyznaczamy nową pozycję znaku

      X0 = ( a * X0 + c ) % m;

      // wymieniamy znaki

      swap ( s [ i ], s [ X0 % s.length( ) ] );
    }

  else
  {
    // odtwarzamy klucz

    X0 = - X0;

    // tworzymy tablicę dynamiczną na pozycje

    T = new int [ s.length( ) ];

    // wyliczamy pozycje jak przy szyfrowaniu

    for( i = 0; i < ( int )s.length( ); i++ )
    {
      X0 = ( a * X0 + c ) % m;
      T [ i ] = X0 % s.length( );
    }

    // wykorzystujemy pozycje od końca szyfru

    for( i = s.length( ) - 1; i >= 0; i-- )
    {
      swap ( s [ i ], s [ T [ i ] ] );
    }

    // usuwamy tablicę dynamiczną

    delete [ ] T;
  }

  // wypisujemy wynik

  cout << s << endl;

  return 0;
} 