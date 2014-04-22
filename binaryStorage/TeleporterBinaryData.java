package com.ankamagames.wakfu.client.binaryStorage;

public class TeleporterBinaryData implements dEZ {
    protected int iyX;
    protected int UA;
    protected int bPa;
    protected short iyY;
    protected int dDw;
    protected short eMC;
    protected boolean dDy;
    protected short iyZ;
    protected int duD;
    protected aem[] iza;
    
    public TeleporterBinaryData()
    {
        super();
    }
    
    public int czO()
    {
        return this.iyX;
    }
    
    public int gX()
    {
        return this.UA;
    }
    
    public int NX()
    {
        return this.bPa;
    }
    
    public short czP()
    {
        int i = this.iyY;
        return (short)i;
    }
    
    public int aDl()
    {
        return this.dDw;
    }
    
    public short bli()
    {
        int i = this.eMC;
        return (short)i;
    }
    
    public boolean aDn()
    {
        return this.dDy;
    }
    
    public short czQ()
    {
        int i = this.iyZ;
        return (short)i;
    }
    
    public int czR()
    {
        return this.duD;
    }
    
    public aem[] czS()
    {
        return this.iza;
    }
    
    public void reset()
    {
        this.iyX = 0;
        this.UA = 0;
        this.bPa = 0;
        this.iyY = (short)0;
        this.dDw = 0;
        this.eMC = (short)0;
        this.dDy = false;
        this.iyZ = (short)0;
        this.duD = 0;
        this.iza = null;
    }
    
    public void a(ceb a)
    {
        this.iyX = a.getInt();
        this.UA = a.getInt();
        this.bPa = a.getInt();
        int i = a.getShort();
        this.iyY = (short)i;
        this.dDw = a.getInt();
        int i0 = a.getShort();
        this.eMC = (short)i0;
        this.dDy = a.readBoolean();
        int i1 = a.getShort();
        this.iyZ = (short)i1;
        this.duD = a.getInt();
        int i2 = a.getInt();
        this.iza = new aem[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.iza[i3] = new aem();
            this.iza[i3].a(a);
            i3 = i3 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEJ.getId();
    }
}