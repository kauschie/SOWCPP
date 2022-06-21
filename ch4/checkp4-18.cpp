/* checkpoint 4.18 
 *
 * Expression               Result (true or false)
 *  true && false                   false
 *  true && true                    true
 *  false && true                   false
 *  false && false                  false
 *  true || false                   true
 *  true || true                    true
 *  false || true                   true
 *  false || false                  false
 *  !true                           false
 *  !false                          true
 *
 *
 *  Chcckpoint 4.19
 *
 *  int a = 2
 *      b = 4
 *      c = 6;
            
        Expression                      Evaluation
 *  A ) a == 4 || b > 2                     True
 *  B ) 6 <= c && a > 3                     False
 *  C ) 1 != b && c != 3                    True
 *  D ) a >= -1 || a <= b                   True
 *  E ) !(a > 2)                            True
 *
 *  Checkpoint 4.20
 *
 *  if (speed >= 0 && speed <= 200)
 *      cout << "The number is valid";
 *
 *  Checkpoint 4.21
 *
 *  if (speed < 0 || speed > 200)
 *      cout << "The number is not valid";
