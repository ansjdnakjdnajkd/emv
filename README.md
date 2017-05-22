# EMV Reader

General
---------------------
- Lang (e.g ru en)
- Financial Service (MasterCard/Visa/..)
- AID
- PAN (eg. 1234 5678 1234 5678)
- Exp. date (e.g 13 01, YYMM format)
- Bank
- Remaining attempts to enter the PIN code (0,1,2,3..)
- Transaction History ( date/sum/currency)
- Transaction counter  
- Response dump (hex)

! Tested on MasterCard & Visa

Require
---------------------
- Install [libNFC](https://github.com/nfc-tools/libnfc)
```
apt-get install libnfc-bin libnfc-dev libnfc-examples
```
or [read wiki](http://nfc-tools.org/index.php?title=Libnfc#Installation)
- Install&Configure driver for reader (e.g. [ACS122U](http://www.acs.com.hk/en/products/3/acr122u-usb-nfc-reader/))

- Install [Ruby](https://www.ruby-lang.org)

Usage
---------------------
Place your HF Smart Card and try nfc-list (it should work, otherwise back to begining)
```
ruby run.rb
```

To-Do
---------------------
- Refresh BIN list
- ???

Author: @ansjdnakjdnajkd 

License: MIT License (opensource.org/licenses/MIT)

Example output

```
Mastercard International
===============
Lang:ruen
PaySYS: Mastercard International | United States | MasterCard Credit | Standard MasterCard | EMV
AID: A0000000041010
===============
Pan: 5401493320261259
Exp: 1603
Bank: Bank of America (formerly MBNA) MasterCard Gold Credit Card
===============
Pin attempt(s): 2 left
===============
Date: 14-02-15
Sum: 1290.0 RUB
• • • • • • • •
Date: 16-10-15
Sum: 2119.0 RUB
• • • • • • • •
Date: 12-09-15
Sum: 2235000.0 VND
• • • • • • • •
Date: 27-05-15
Sum: 683140.0 VND
• • • • • • • •
Date: 03–07-15
Sum: 1103860.0 VND
• • • • • • • •
Date: 01-10-15
Sum: 15.51 USD
===============
Application Transaction Counter: n/a
===============
Dump
[…]
```
