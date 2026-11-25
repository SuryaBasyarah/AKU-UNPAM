use std::io::{self, Write};

const MAX: usize = 5;

struct CircularQueue {
    data: [i32; MAX],
    front: usize,
    rear: usize,
    count: usize,
}

impl CircularQueue {
    fn new() -> Self {
        CircularQueue {
            data: [0; MAX],
            front: 0,
            rear: 0,
            count: 0,
        }
    }

    fn is_empty(&self) -> bool {
        self.count == 0
    }

    fn is_full(&self) -> bool {
        self.count == MAX
    }

    // Menambahkan data ke queue
    fn enqueue(&mut self, value: i32) {
        if self.is_full() {
            println!("Queue penuh!");
            return;
        }

        self.data[self.rear] = value;

        // Rear bergerak secara melingkar
        self.rear = (self.rear + 1) % MAX;

        self.count += 1;

        println!("{} berhasil ditambahkan.", value);
    }

    // Menghapus data paling depan
    fn dequeue(&mut self) {
        if self.is_empty() {
            println!("Queue kosong!");
            return;
        }

        let value = self.data[self.front];

        // Front bergerak secara melingkar
        self.front = (self.front + 1) % MAX;

        self.count -= 1;

        println!("{} berhasil dikeluarkan.", value);
    }

    // Menampilkan seluruh isi queue
    fn display(&self) {
        if self.is_empty() {
            println!("Queue kosong!");
            return;
        }

        print!("\nIsi Queue: ");

        for i in 0..self.count {
            let index = (self.front + i) % MAX;
            print!("{} ", self.data[index]);
        }

        println!();
    }
}

fn input_number() -> i32 {
    let mut input = String::new();

    io::stdin()
        .read_line(&mut input).expect("Gagal membaca input");

    input
        .trim().parse().expect("Input harus berupa angka")
}

fn main() {
    let mut queue = CircularQueue::new();

    loop {
        println!();
        println!("=== CIRCULAR QUEUE ===");
        println!("1. Enqueue");
        println!("2. Dequeue");
        println!("3. Tampilkan Queue");
        println!("4. Keluar");

        print!("Pilih menu: ");
        io::stdout().flush().unwrap();

        let pilihan = input_number();

        match pilihan {
            1 => {
                print!("Masukkan data: ");
                io::stdout().flush().unwrap();

                let data = input_number();
                queue.enqueue(data);
            }

            2 => {
                queue.dequeue();
            }

            3 => {
                queue.display();
            }

            4 => {
                println!("Program selesai.");
                break;
            }

            _ => {
                println!("Pilihan tidak tersedia.");
            }
        }
    }
}