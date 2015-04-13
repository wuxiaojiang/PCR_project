import server
pcr_server = server.pcr_control_server()
sock = pcr_server.build_udp('',1080)
print pcr_server.port
pcr_server.run_udp(sock)
