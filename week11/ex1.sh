dd if=/dev/zero of=lofs.img bs=100M count=10
sudo losetup -fP lofs.img
mkfs lofs.img
sudo mount -o loop /dev/loop11 lofsdisk
