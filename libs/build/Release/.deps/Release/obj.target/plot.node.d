cmd_Release/obj.target/plot.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=plot.node -o Release/obj.target/plot.node -Wl,--start-group Release/obj.target/plot/plot.o -Wl,--end-group 
