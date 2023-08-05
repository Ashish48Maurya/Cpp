/*    case-1 (both digits are 0)
     ans=0 if no previous carry
     ans=1 if privious carry

       case-2 (one digit is 0, other is 1)
     ans=0 if previous carry generate further carry
     ans=1 if no previous carry no further carry generated

       case-3 (both digit are 1)
    ans=0 if no previous carry  but carry will be generated
    ans=1 if previous carry
*/
