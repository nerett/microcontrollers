#include <LiquidCrystal.h>

const int rs = PB11, en = PB10, d4 = PB0, d5 = PB1, d6 = PC13, d7 = PC14;
const int timer_period = 1000000;
const int interface_update_period = 300;

LiquidCrystal lcd( rs, en, d4, d5, d6, d7 );
volatile boolean isMeasuring = false;
volatile int currentInterval = 0;
volatile int bestInterval = 0;

void setup()                                                      
{
  lcd.begin( 16, 2 );
  
  lcd.print( "MC MIPT project" );
  lcd.setCursor( 0, 1 );
  lcd.print( "2023" );
  delay( 1000 );

  lcd.clear();
  lcd.print( "by: Tsedrik" );
  lcd.setCursor( 0, 1 );
  lcd.print( "Vikhlyantsev" );
  delay( 2000 );

  pinMode( PA1, OUTPUT );
  pinMode( PA0, INPUT );
  attachInterrupt( PA0, onButtonPush, FALLING );

  digitalWrite( PA1, LOW );

  Timer3.pause();
  Timer3.setPeriod( timer_period );
  Timer3.attachInterrupt( TIMER_UPDATE_INTERRUPT, onTimerUpdate );

  lcd.clear();
}

void loop()
{
  if( isMeasuring )
  {
    lcd.clear();
    lcd.print( "Time:" );
    lcd.print( currentInterval );
  }
  else
  {
    lcd.clear();
    lcd.print( "Loop:" );
    lcd.print( currentInterval );

    if( bestInterval )
    {
      lcd.setCursor( 0, 1 );
      lcd.print( "Best:" );
      lcd.print( bestInterval );
    }
  }

  delay( interface_update_period );
}
  
void onButtonPush()
{
  if( isMeasuring )
  {
    endMeasurement();
  }
  else
  {
    startMeasurement();
  }
}

void onTimerUpdate()
{
  ++currentInterval;
}

void startMeasurement()
{
  Timer3.refresh();
  Timer3.resume();
  currentInterval = 0;
  
  isMeasuring = true;
  digitalWrite( PA1, HIGH );
}

void endMeasurement()
{
  Timer3.pause();
  
  isMeasuring = false;
  digitalWrite( PA1, LOW );

  if( !bestInterval || currentInterval < bestInterval )
  {
    bestInterval = currentInterval;
  }
}
