require "readline"

CHARACTER_NAMES = [
  "Arthur Dent",
  "Ford Prefect",
  "Tricia McMillan",
  "Zaphod Beeblebrox",
].freeze

Readline.completion_proc = proc do |input|
  CHARACTER_NAMES.select { |name| name.start_with?(input) }
end

puts "Who's your favourite Hitchiker's Guide character?"
input = Readline.readline("> ", false)
if input
  puts "You entered: #{input}"
end
