extern crate rand;
use rand::prelude::*;
use std::thread;

static NTHREADS: i32 = 8;
static ITERATIONS: i64 = 100000000;

fn calc_e() -> f64 {
    let i: i64 = ITERATIONS;
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
    return  t_sum / i as f64;
}

fn average(numbers: &[f64]) -> f64 {
    numbers.iter().sum::<f64>() as f64 / numbers.len() as f64
}


fn main() {
    // let res = calc_e();
    // println!("{}", res);
    
    let mut children = vec![];
    for _i in 0..NTHREADS {
        // Spin up another thread
        children.push(thread::spawn(move || -> f64 {
            let res = calc_e();
            res
        }));
    }

    let mut thread_results = vec![];
    for child in children {
        // Wait for the thread to finish. Returns a result.
        let res = child.join().unwrap();
        thread_results.push(res);
    }
    println!("{:?}", average(&thread_results));
    
}
