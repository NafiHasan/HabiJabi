int grundyValue[ Nn ];
int mexValue[ Nn ], MEX;
void calculateGrundyValue() {
      grundyValue[ 1 ] = grundyValue[ 2 ] = 0;
      for ( int i = 3; i <= 10000; ++i ) {
            for ( int j = 1; j + j < i; ++j )
                  mexValue[ grundyValue[ j ] ^ grundyValue[ i - j ] ] = i;
            MEX = 0;
            while ( mexValue[ MEX ] == i )
                  MEX++;
            grundyValue[ i ] = MEX;
      }
}
void solve( int t ) {
      int N, a;
      cin >> N;
      int XOR = 0;
      while ( N-- ) {
            cin >> a;
            XOR ^= grundyValue[ a ];
      }
      cout << "Case " << t << ": ";
      if ( XOR )   cout << "Alice\n";
}