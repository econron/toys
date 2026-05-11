module MyApp
  class Server
    def start_control
      token = "secret"
      require_relative "status_app" # 必要になったタイミングで読む
      app = MyApp::StatusApp.new "server1",token: token,data_only: false
      puts app.call("ok")
    end
  end
end

server = MyApp::Server.new
server.start_control