puts "PID: #{Process.pid}"

Signal.trap "TERM" do
  puts "SIGTERM received"
  puts "cleanup..."
  exit
end

Signal.trap "INT" do
  puts "SIGINT received"
  puts "bye"
  exit
end

loop do
  puts "running...."
  sleep 2
end