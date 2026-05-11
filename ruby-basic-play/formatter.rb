module MyApp
  module Formatters
    module Prefix
      def prefix(text)
        "[app] #{text}"
      end
    end
  end
end