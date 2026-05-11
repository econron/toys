require_relative "formatter"

module MyApp
  class StatusApp
    include ::MyApp::Formatters::Prefix

    def initialize(name, token: nil, data_only: false)
      @name = name
      @token = token
      @data_only = data_only
    end

    def call(message)
      return message if @data_only

      prefix("#{@name}: #{message}, token=#{@token}")
    end
  end
end