#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void){
	srand(time(NULL));   // Initialization, should only be called once.

	unsigned int i = 100000000;
	unsigned int t_sum = 0;
	printf("%d\n", MAX_INT);
	for (unsigned int n = 0; n < i; n++) {
		float x = 0;
		unsigned int digits = 0;
		while (1) {
			x+=rand()/(double)RAND_MAX;
			digits+=1;
			if (x > 1.0) {
                t_sum += (float)digits;
                break;
            }
		}
	}
	printf("%f\n", (t_sum / (float)i));
	return 0;
}



// extern crate rand;
// use rand::prelude::*;

// fn main() {
//     let i: i64 = 1000000000;
//     let mut t_sum: f64 = 0.0;
//     let mut rng = thread_rng();
//     for _n in 1..i {
//         let mut x: f64 = 0.0;
//         let mut digits: i32 = 0;
//         loop {
//             let r:f64 = rng.gen();
//             x += r;
//             digits += 1;
//             if x > 1.0 {
//                 t_sum += digits as f64;
//                 break;
//             }
//         }
//     }
//     println!("{}", t_sum / i as f64);
// }
