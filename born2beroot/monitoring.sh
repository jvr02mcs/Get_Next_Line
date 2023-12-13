#ARCHITECTURE
arch=$(uname -a)
#PHISICAL CPU
cpu_ph=$(nproc)
#VIRTUAL CPU
cpu_v=$(lscpu | grep "Thread(s) per core" | awk ' {print $4}')
#RAM
ram_info=$(free --mega | awk '$1 == "Mem:" {
    used_ram = $3
    total_ram = $2
    av_ram = total_ram - used_ram
}
END {
    ram_percent = (used_ram / total_ram) * 100
    printf "%d / %d MB (used:%.2f%%)\n", av_ram, total_ram, ram_percent
}')
#DISK
disk_info=$(df -m | awk '"Mem:" {
    disk_total += $2
    disk_used += $3
}
END {
    disk_percent = (disk_used / disk_total) * 100
    printf "%d MB / %d GB (%.2f%%)\n", disk_used, disk_total/1024, disk_percent
}')
#LAST BOOT
last_boot=$(who -b | awk '$1 == "system" {print $3 " " $4 " " $5}')
#LVM!!!!
is_lvm_on=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)
#CONEXIONES ACTIVAS !!!!!!!!!!!!!!!!!!!!!!!!
active_con=$(ss -ta | grep ESTAB | wc -l)
#USERS
n_users=$(users | wc -w)
#IP&MAC
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')
#FINAL
wall "Architecture : $arch
Avaliable RAM : $ram_info
phisical cpu : $cpu_ph
virtual cpu : $cpu_v
Last boot : $last_boot
Disk : $disk_info
LVM $is_lvm_on
Active connections : $active_con
Number of users : $n_users"