fn selection_sort(data: &mut [i32]) {
    let n = data.len();

    for i in 0..n {
        let mut min_index = i;

        for j in (i + 1)..n {
            if data[j] < data[min_index] {
                min_index = j;
            }
        }

        data.swap(i, min_index);
    }
}

fn main() {
    let mut data = [64, 25, 12, 22, 11];
    println!("=== Selection Sort ===");
    println!("Data sebelum diurutkan: {:?}", data);

    selection_sort(&mut data);

    println!("Data setelah diurutkan: {:?}", data);
}

// Surya Basyarah Putra
// 251011402227
// 03TPLE011