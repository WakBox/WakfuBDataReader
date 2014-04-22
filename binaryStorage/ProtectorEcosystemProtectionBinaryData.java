package com.ankamagames.wakfu.client.binaryStorage;

public class ProtectorEcosystemProtectionBinaryData implements dEZ {
    protected int aNN;
    protected bBi[] ndG;
    protected Dn[] ndH;
    
    public ProtectorEcosystemProtectionBinaryData()
    {
        super();
    }
    
    public int Et()
    {
        return this.aNN;
    }
    
    public bBi[] dKf()
    {
        return this.ndG;
    }
    
    public Dn[] dKg()
    {
        return this.ndH;
    }
    
    public void reset()
    {
        this.aNN = 0;
        this.ndG = null;
        this.ndH = null;
    }
    
    public void a(ceb a)
    {
        this.aNN = a.getInt();
        int i = a.getInt();
        this.ndG = new bBi[i];
        int i0 = 0;
        while(i0 < i)
        {
            this.ndG[i0] = new bBi();
            this.ndG[i0].a(a);
            i0 = i0 + 1;
        }
        int i1 = a.getInt();
        this.ndH = new Dn[i1];
        int i2 = 0;
        while(i2 < i1)
        {
            this.ndH[i2] = new Dn();
            this.ndH[i2].a(a);
            i2 = i2 + 1;
        }
    }
    
    final public int gZ()
    {
        return aPw.eEu.getId();
    }
}