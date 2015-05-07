<?php 

$host = "192.168.11.139";
$port = 5353;
// No Timeout 
set_time_limit(0);

$message = "Hello Server";
echo "Message To server :".$message;

$socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP ) or die("Could not create socket\n");

$result = socket_connect($socket, $host, $port) or die("Could not connect toserver\n");

socket_write($socket, $message, strlen($message)) or die("Could not send data to server\n");

$result = socket_read ($socket, 1024) or die("Could not read server response\n");
echo "Reply From Server  :".$result;
?>