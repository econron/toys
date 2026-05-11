# 起動時のPIDを取得する
puts "PID: #{Process.pid}"

# TERMを受け取ったらcleanupと出してexit
Signal.trap "TERM" do
  puts "SIGTERM received"
  puts "cleanup..."
  exit
end

# INTを受け取ったらbyeしてexit
Signal.trap "INT" do
  puts "SIGINT received"
  puts "bye"
  exit
end

# exitしない限りはrunningを出し続ける
loop do
  puts "running...."
  sleep 2
end