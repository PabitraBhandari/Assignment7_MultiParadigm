let rec count x lst =
  match lst with
  | [] -> 0
  | h :: t -> if h = x then 1 + count x t else count x t

let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted (len/2 - 1) in
    let mid2 = List.nth sorted (len/2) in
    (float_of_int (mid1 + mid2)) /. 2.0
  else
    float_of_int (List.nth sorted (len/2))

let mode lst =
  let rec unique l = match l with
    | [] -> []
    | h::t -> if List.mem h t then unique t else h::(unique t)
  in
  let uniq = unique lst in
  let counts = List.map (fun x -> (x, count x lst)) uniq in
  let max_count = List.fold_left (fun acc (_, c) -> max acc c) 0 counts in
  let modes = List.filter (fun (_, c) -> c = max_count) counts in
  List.map fst modes

let () =
  let lst = [1; 2; 2; 3; 4; 4; 4; 5] in
  Printf.printf "Mean: %.2f\n" (mean lst);
  Printf.printf "Median: %.2f\n" (median lst);
  Printf.printf "Mode(s): ";
  List.iter (Printf.printf "%d ") (mode lst);
  print_newline ()
