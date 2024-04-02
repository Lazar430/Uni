module testbench();

    //Inputs
    reg [3:0]c;

    //Outputs
    wire [6:0]seg;

    hex DUT(
        .c(c),
        .seg(seg)
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
