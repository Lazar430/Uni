module testbench();

    //Inputs
    reg [3:0]c;

    //Outputs
    wire f;

    hex DUT(
        .c(c),
        .f(f)
    );

    initial begin
        //initilize
       c = 0;
       

        #100;
    end

    always begin
       #25 c = c + 1;
    end
endmodule
