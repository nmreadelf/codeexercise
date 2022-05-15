use std::fs;

fn main() {
    let dir = fs::read_dir(".").unwrap();

    for p in dir {
        println!("{}", p.unwrap().path().display());
    }
}
