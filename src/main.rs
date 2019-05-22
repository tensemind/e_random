extern crate rand;
use rand::prelude::*;

fn main() {
    let i: i32 = 1000000;
    let mut t_sum: f64 = 0.0;
    let mut rng = thread_rng();
    for _n in 1..i {
        let mut x: f64 = 0.0;
        let mut digits: i32 = 0;
        loop {
            let r:f64 = rng.gen();
            x += r;
            digits += 1;
            if x > 1.0 {
                t_sum += digits as f64;
                break;
            }
        }
    }
    println!("{}", t_sum / i as f64);
}
