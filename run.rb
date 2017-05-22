require './aid.rb'
require './bin.rb'
require './cur.rb'

$pay = nil
$aid = nil
$dump = []

def pAID(a)
    $codeAID.each do |key, val|
        if a.split(' ').join('').downcase.include? key.strip.downcase
            $aid = key.strip.split("	").join(' | ')
            $pay = val.strip.split(' ')[0..1].join(' ')
        end
    end
end

def pHistory(a)
    a = a.split(' ')
    puts 'Date: ' + a[9..11].reverse.join('-')
    puts 'Sum: ' + (a[1..6].join('').to_f / 100).to_s + ' ' + $codeCur.invert[a[7..8].join('')[1..-1]]
    puts "• • • • • • • •"
end

def pPin(a)
    a = a.split(' ')
    puts 'Pin attempt(s): ' + a[3].to_i.to_s + ' left'
end

def pPanExp(a, p)
    a = a.split(' ')
    # puts "A: "
    # puts a
    pan = exp = ''
    if p == 'm'
        (0..a.length - 1).each do |i|
            next unless a[i] == '56' && a[i + 2] == '42'
            (i + 3..i + 18).each do |j|
                pan += a[j].hex.chr
            end
            (i + 23..i + 26).each do |j|
                exp += a[j].hex.chr
            end
            break
        end
    else
        pan = a[4..11].join('')
        exp = a[12..14].join('')[1..-2]
    end
    puts 'Pan: ' + pan
    puts 'Exp: ' + exp
    $codeBIN.each do |key, val|
        if pan.include? key.strip.downcase
            puts 'Bank: ' + val.strip.split("	").join(' | ')
        end
    end
end

def pCurrencySupport(a)
    a = a.split(' ')
    lang = ''
    (0..a.length - 1).each do |i|
        if i > 30 && (a[i] != '6e' || a[i + 2] != '9f')
            lang += a[i].hex.chr
            break if a[i] == '6e' || a[i] == '9f'
        end
    end
    puts 'Lang:' + lang

    $codeAID.each do |key, val|
        if a.join('').include? key.strip.downcase
            puts 'PaySYS: ' + val.strip.split("	").join(' | ')
        end
    end
    puts 'AID: ' + $aid
end

def pTrCount(a)
    if a.downcase.include? '6a 8'
        puts 'Application Transaction Counter: n/a'
    else
        a = a.split(' ')
        puts 'Application Transaction Counter: ' + a[3].hex.to_s + a[4].hex.to_s
    end
end

c = 'gcc exec.c -lnfc && ./a.out 1'
k = IO.popen(c)
a = k.readlines.reject { |c| c.empty? || c == "\n" }
$dump.concat(a)
pAID(a.to_s)
puts $pay

c =  'gcc exec.c -lnfc && ./a.out ' + $pay.downcase.split(' ')[0][0]
k = IO.popen(c)
z = k.readlines.reject { |c| c.empty? || c == "\n" }
$dump.concat(z)
puts '==============='
pCurrencySupport(z[0])
puts '==============='
pPanExp(z[1], $pay.downcase.split(' ')[0][0])
puts '==============='
pPin(z[2])
puts '===============' 

if z[4].split(' ')[0..1].join(' ').include? '6a 8'
    puts 'Transactions: n/a'
else
    (4..z.length - 1).each do |i|
        pHistory(z[i]) unless z[i].include? '6a 83'
    end
end
puts '==============='

c =  'gcc exec.c -lnfc && ./a.out ' + $pay.downcase.split(' ')[0][1]
k = IO.popen(c)
z = k.readlines.reject { |c| c.empty? || c == "\n" }
$dump.concat(z)
pTrCount(z[1])
puts '==============='

puts 'Dump'
puts $dump
