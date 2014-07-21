package com.ankamagames.wakfu.client.binaryStorage;

public class AptitudeBinaryData implements dEZ {
    protected int az;
    protected short aZG;
    protected byte kVw;
    protected int hle;
    protected int hlh;
    protected int hli;
    protected short aZF;
    protected int hlj;
    protected int[] kVx;
    protected int dsa;
    protected int[] kVy;
    protected int[] bav;
    
    public AptitudeBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short vV()
    {
        int i = this.aZG;
        return (short)i;
    }
    
    public byte cSl()
    {
        int i = this.kVw;
        return (byte)i;
    }
    
    public int bZW()
    {
        return this.hle;
    }
    
    public int bZX()
    {
        return this.hlh;
    }
    
    public int bZY()
    {
        return this.hli;
    }
    
    public short oE()
    {
        int i = this.aZF;
        return (short)i;
    }
    
    public int cSm()
    {
        return this.hlj;
    }
    
    public int[] cSn()
    {
        return this.kVx;
    }
    
    public int aye()
    {
        return this.dsa;
    }
    
    public int[] cSo()
    {
        return this.kVy;
    }
    
    public int[] wK()
    {
        return this.bav;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aZG = (short)0;
        this.kVw = (byte)0;
        this.hle = 0;
        this.hlh = 0;
        this.hli = 0;
        this.aZF = (short)0;
        this.hlj = 0;
        this.kVx = null;
        this.dsa = 0;
        this.kVy = null;
        this.bav = null;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.aZG = (short)i;
        int i0 = a.get();
        this.kVw = (byte)i0;
        this.hle = a.getInt();
        this.hlh = a.getInt();
        this.hli = a.getInt();
        int i1 = a.getShort();
        this.aZF = (short)i1;
        this.hlj = a.getInt();
        this.kVx = a.cli();
        this.dsa = a.getInt();
        this.kVy = a.cli();
        this.bav = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEP.getId();
    }
}