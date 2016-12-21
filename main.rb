require "readline"

CHARACTER_NAMES = [
  "Arthur Dent",
  "Ford Prefect",
  "Tricia McMillan",
  "Zaphod Beeblebrox",
].freeze

Readline.completer_quote_characters = "\"'"
Readline.completer_word_break_characters = " "

Readline.quoting_detection_proc = proc do |input, index|
  index > 0 && input[index - 1] === "\\" &&
    !Readline.quoting_detection_proc.call(input, index-1)
end

Readline.completion_proc = proc do |input|
  options = CHARACTER_NAMES
  if Readline.completion_quote_character.nil?
    options = options.map { |o| o.gsub(" ", "\\ ") }
  end

  options.select { |name| name.start_with?(input) }
end

puts "Who's your favourite Hitchiker's Guide character?"
input = Readline.readline("> ", false)
if input
  puts "You entered: #{input}"
end
