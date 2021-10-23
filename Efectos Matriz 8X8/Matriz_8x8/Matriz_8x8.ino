//Creditos: https://www.prometec.net/matriz-led-8x8/
//Editado por Electronics ARME
//.................................................

// EFECTO 1 ENTRA Y SALE  
byte A[]=  { 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00 }; // 4 del centro
byte B[]=  { 0x00, 0x00, 0x3C, 0x3C, 0x3C, 0x3C, 0x00, 0x00 }; // 16 del centro
byte C[]=  { 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x00 }; // 36 del centro
byte D[]=  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //TODOS prendidos 
byte F[]=  { 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // TODOS  apagados 
byte G[]=  { 0xFF, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0xFF }; //36  apagado 
byte H[]=  { 0xFF, 0xFF, 0xC3, 0xC3, 0xC3, 0xC3, 0xFF, 0xFF }; // 16 apagado
byte I[]=  { 0xFF, 0xFF, 0xFF, 0xE7, 0xE7, 0xFF, 0xFF, 0xFF };// 4 apagado 

// EFECTO 2 CORAZON

byte E[]=  { 0xC, 0x12, 0x22, 0x44, 0x22, 0x12, 0xC, 0x00 }; //vacio
byte J[]=  { 0x0C, 0x1E, 0x3E, 0x7C, 0x3E, 0x1E, 0x0C, 0x00 };// lleno

// EFECTO 3  CADENA
byte K[]=  { 0x81, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81 }; // 
byte M[]=  { 0xC1, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x83 }; //
byte N[]=  { 0xE1, 0x01, 0x01, 0x00, 0x00, 0x80, 0x80, 0x87 };   //  
byte O[]=  { 0xF1, 0x01, 0x01, 0x01, 0x80, 0x80, 0x80, 0x8F };   //
byte P[]=  { 0xF9, 0x01, 0x01, 0x81, 0x81, 0x80, 0x80, 0x9F };   // 
byte Q[]=  { 0xFD, 0x01, 0x81, 0x81, 0x81, 0x81, 0x80, 0xBF }; //
// BARRIDO 1 
byte R[]=  { 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte S[]= { 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00,  0x00 };
byte T[]=  { 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00 };
byte U[]=  { 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00 };
byte V[]=  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00 };
byte W[]=  { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };

// EFECTO CRUZ
byte X[]=  { 0xC3, 0xC3, 0x00, 0x00, 0x00, 0x00, 0xC3, 0xC3 };
byte Z[]=  { 0xE7, 0xE7, 0xE7, 0x00, 0x00, 0xE7, 0xE7, 0xE7 };

byte Y[]=  { 0x80, 0x40, 0x60, 0x10, 0x08, 0x04, 0x02, 0x01 }; // DIAGONAL 


//......................................................................................



void setup()         
    {   for (int j=2; j<19; j++)        ///Definimos todos los pines del arduino como salida
              pinMode(j, OUTPUT);         
       Serial.begin(9600);
    }
void SetChar(char p) 
{    
     Clear();
     for (int fil = 0; fil <8 ; fil++)
        {
            digitalWrite( fil + 10 , HIGH) ; 
            //byte F = N[fil] ;
            byte F = Selecciona( p, fil);
                         
            for (int col =7; col >= 0 ; col--)
                {  
                    digitalWrite(8-col, HIGH);     
                    bool b = GetBit(F, col)  ;
                    if (b)
                        digitalWrite( 9 - col  ,LOW); 
                    else
                        digitalWrite( 9 - col  ,HIGH); 

                 }                                    
            digitalWrite( fil + 10 , LOW) ;         
          }
}

 
bool GetBit( byte N, int pos)
{                              // pos = 7 6 5 4 3 2 1 0
    int b = N >> pos ;         // Shift bits
    b = b & 1 ;                // coger solo el ultimo bit
    return b ;
}
void Clear()
{
   for (int j=2; j<10; j++)  // Valores de los pines de columna
        digitalWrite(j, HIGH); // Todos apagados
         
   for (int k= 10 ; k<18 ; k++)
        digitalWrite(k, LOW); // Todas las filas cortadas
 }

 
// POR CADA LETRA AGREGA AL INICIO DEL PROGRAMA, SE TIENE QUE  AGREGAR "if (c == 'NUEVA LETRA') return(NUEVA LETRA[fil]) ;"
 byte Selecciona( char c, byte fil)
{
  


  if (c == 'A')           return( A[fil]);
  if (c == 'B')           return( B[fil]);
  if (c == 'C')           return( C[fil]);
  if (c == 'D')           return( D[fil]);
  if (c == 'E')           return( E[fil]);
  if (c == 'F')           return( F[fil]);
  if (c == 'G')           return( G[fil]);
  if (c == 'H')           return( H[fil]);
   if (c == 'I')           return( I[fil]);
  if (c == 'J')           return( J[fil]);
  if (c == 'K')           return( K[fil]);
  if (c == 'M')           return( M[fil]);
  if (c == 'N')           return( N[fil]);
  if (c == 'O')           return( O[fil]);
  if (c == 'P')           return( P[fil]);
  if (c == 'Q')           return( Q[fil]); 
    if (c == 'R')           return( R[fil]);
  if (c == 'S')           return( S[fil]);
  if (c == 'T')           return( T[fil]);
  if (c == 'V')           return( V[fil]);
  if (c == 'U')           return( U[fil]);
  if (c == 'X')           return( X[fil]);
  if (c == 'Y')           return( Y[fil]);
  if (c == 'Z')           return( Z[fil]);
  
}

//......................................................


void loop()
{
String s = " KMNOPQGKMNOPQGKMNOPQG Y KMNOPQGKMNOPQGKMNOPQG Y GQPONMKGQPONMKGQPONMK KMNOPQGKMNOPQGKMNOPQG    XZD Y DZXDZXDZX YY XZDXZDXZD  Y JEJEJEJEJEJEJEJEJEJEJE Y  FRSTUVWDFRSTUVWD  DWVUTSRFDWVUTSRF   ABCDFGHIDABCDFGHID  Y DIHGFDCBADIHGFDCBA  " ;//  TEXTO A MOSTRAR
  int l = s.length();      // Calcula la longitus de s
  for ( int n = 0; n< l; n++ )
    {
      long t = millis();
      char c = s[n];
      while ( millis()< t+ 50) //Se difine el tiempo de cambio de letra.
            SetChar(c);

    }
   
  }
  
  
