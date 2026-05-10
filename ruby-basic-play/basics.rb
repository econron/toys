# クラスとか変数とか
class User
  def initialize(name)
    # @がつくとインスタンス変数
    @name = name
  end

  def greet
    puts "hello, #{@name}-san"
  end

  def open_mind
    greet_private
  end

  private
  def greet_private
    puts "what's up bro."
  end
end

class App
  attr_reader :user

  def initialize
    @user = User.new("econron2")
  end
end

# userはローカル変数
user = User.new("econron")
user.greet

# userを外から参照させる
app = App.new()
app.user.greet
# app.user.greet_private 流石にprivateメソッドを呼び出すとエラー
app.user.open_mind

# call できるオブジェクトを渡して、処理を差し替える
class Plain
  def call(s)
    s
  end
end

class Upcase
  def call(s)
    s.upcase
  end
end

def print_with(formatter, text)
  puts formatter.call(text)
end

print_with(Plain.new, "hello")
print_with(Upcase.new, "hello")

# ネストしたクラス
class NestedApp
  class NestedFormatter
    def call(str)
      str.upcase
    end
  end
end

formatter = NestedApp::NestedFormatter.new
puts formatter.call("hello")