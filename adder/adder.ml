open Printf

let half_adder (a, b) =
        let s = a <> b (* xor *)
        and c = a && b in
                (s, c);;

let full_adder (input_a, input_b, carry_in) =
        let s, carry_out = half_adder (input_a, input_b) in
        let sum, c       = half_adder (carry_in, s) in
        sum, (carry_out || c);;

let full_adderi (input_a, input_b, carry_in) =
        let i2b i = if i=0 then false else true in (* int to bool *)
        let b2i b = if b then 1 else 0 in (* bool to int *)
        let a = i2b input_a in
        let b = i2b input_b in
        let cin = i2b carry_in in
        let s, c = full_adder (a, b, cin) in
                (b2i s), (b2i c);;

let (sum, carry_in) = full_adderi (1, 1, 1) in
printf "%d %d\n" sum carry_in

let pack_int f =
        let i2b i = if i=0 then false else true in
        let b2i b = if b then 1 else 0 in
        function (a, b, c) ->
                let x, y = f ((i2b a), (i2b b), (i2b c)) in
                (b2i x), (b2i y);;

let full_adderi = pack_int full_adder;;


let (sum, carry_in) = full_adderi (1, 1, 1) in
printf "%d %d\n" sum carry_in
