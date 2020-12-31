greet = Greet.new
speaker = Speaker.new(26)
volume = 0
while true
  # greet.hola
  speaker.volume(255)
  speaker.volume(0)
  # sleep 1
  # volume = (volume + 10) % 256
end
