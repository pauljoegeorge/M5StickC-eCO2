class Speaker
  def initialize(pin)
    @pin = pin
    gpio_init_output(@pin)
    volume(0)
  end

  def volume(volume)
    gpio_set_level(@pin, volume)
    puts "volume: #{volume}"
  end
end
