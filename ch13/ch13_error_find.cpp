// 73)  no colon after class name, colons after access specifiers, ; at the end of the class
//
// 74)  semicolons after Private and Public are supposed to be colons
//      constructor is supposed to be Moon
//      supposed to be cout << 
//      supposed to be cin >>
//
// 75)  No semicolon after Dumbell class name
//      need scope resolution operator for
//          void DumbBell::setWeight(int w)
//      Cant pass parameter to Dumbell, need to use setter function:
//          bar.setWeight(200);
//      Can't directly access private parameter weight with bar.weight,
//          need to write getter function
// 76)  Change class has two default constructors because the overloaded constructor
//          has default paramaters for every parameter. The compiler won't know which constructor
//          to call. Additionally, the data type was left out for variables d and q.
//      function header should read:
//          void Change::Change(int p, int n, int d, int q)
//
// 
//      
