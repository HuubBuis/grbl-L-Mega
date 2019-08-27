/*
  serial.c - Low level functions for sending and recieving bytes via the serial port
  Part of Grbl

  Copyright (c) 2011-2016 Sungeun K. Jeon for Gnea Research LLC
  Copyright (c) 2009-2011 Simen Svale Skogsrud

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef serial_h
#define serial_h


#ifndef RX_BUFFER_SIZE
  #define RX_BUFFER_SIZE 255
#endif
#ifndef TX_BUFFER_SIZE
  #define TX_BUFFER_SIZE 255
#endif

#define SERIAL_NO_DATA 0xff


#if defined SERIAL1
// Serial port interrupt vectors
  #define SERIAL_RX USART1_RX_vect
  #define SERIAL_UDRE USART1_UDRE_vect
  //Serial port register definition
  #define  UCSRXA UCSR1A
  #define  UBRRXH UBRR1H
  #define  UBRRXL UBRR1L
  #define  UCSRXB UCSR1B
  #define  UDRIEX UDRIE1
  #define  UDRX UDR1
  #define  U2XX U2X1
  #define  RXCIEX RXCIE1
  #define  TXENX TXEN1
  #define  RXENX RXEN1
#elif defined SERIAL2
  // Serial port interrupt vectors
  #define SERIAL_RX USART2_RX_vect
  #define SERIAL_UDRE USART2_UDRE_vect
  //Serial port register definition
  #define  UCSRXA UCSR2A
  #define  UBRRXH UBRR2H
  #define  UBRRXL UBRR2L
  #define  UCSRXB UCSR2B
  #define  UDRIEX UDRIE2
  #define  UDRX UDR2
  #define  U2XX U2X2
  #define  RXCIEX RXCIE2
  #define  TXENX TXEN2
  #define  RXENX RXEN2
#elif defined SERIAL3
  // Serial port interrupt vectors
  #define SERIAL_RX USART3_RX_vect
  #define SERIAL_UDRE USART3_UDRE_vect
  //Serial port register definition
  #define  UCSRXA UCSR3A
  #define  UBRRXH UBRR3H
  #define  UBRRXL UBRR3L
  #define  UCSRXB UCSR3B
  #define  UDRIEX UDRIE3
  #define  UDRX UDR3
  #define  U2XX U2X3
  #define  RXCIEX RXCIE3
  #define  TXENX TXEN3
  #define  RXENX RXEN3
#else
  //Atleast one serial port should be defined
  #ifndef SERIAL0	
     #warning No serial port defined, using SERIAL0
  #endif
  // Serial port interrupt vectors
  #define SERIAL_RX USART0_RX_vect
  #define SERIAL_UDRE USART0_UDRE_vect
  //Serial port register definition
  #define  UCSRXA UCSR0A
  #define  UBRRXH UBRR0H
  #define  UBRRXL UBRR0L
  #define  UCSRXB UCSR0B
  #define  UDRIEX UDRIE0
  #define  UDRX UDR0
  #define  U2XX U2X0
  #define  RXCIEX RXCIE0
  #define  TXENX TXEN0
  #define  RXENX RXEN0
#endif

void serial_init();

// Writes one byte to the TX serial buffer. Called by main program.
void serial_write(uint8_t data);

// Fetches the first byte in the serial read buffer. Called by main program.
uint8_t serial_read();

// Reset and empty data in read buffer. Used by e-stop and reset.
void serial_reset_read_buffer();

// Returns the number of bytes available in the RX serial buffer.
uint8_t serial_get_rx_buffer_available();

// Returns the number of bytes used in the RX serial buffer.
// NOTE: Deprecated. Not used unless classic status reports are enabled in config.h.
uint8_t serial_get_rx_buffer_count();

// Returns the number of bytes used in the TX serial buffer.
// NOTE: Not used except for debugging and ensuring no TX bottlenecks.
uint8_t serial_get_tx_buffer_count();

#endif
