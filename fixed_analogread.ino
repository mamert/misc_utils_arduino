# source: http://forum.arduino.cc/index.php/topic,133261.0.html

# problem it fixes: very poor distribution of reads from floating pin




unsigned short myanalogRead(unsigned char pin) {
  ADMUX = 0x00;  //Vref = DEFAULT, adc on adc0, right justified
  ADCSRA =  (1<<ADEN) |    //enable adc
            (0<<ADSC) |    //don't start the adc yet
            (0<<ADATE) |  //no auto sampling
            (1<<ADIF) |    //clear adc flag by writing 1 to it
            (0<<ADIE) |    //no adc interrupt
            (1<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);  //1/16 adc prescaler
  ADCSRA |= (1<<ADSC);      //start the conversion
  while (ADCSRA & (1<<ADSC)) continue; //wait for the conversion to end
  
  
  return ADC;
}
